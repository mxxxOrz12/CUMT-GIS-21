const express = require("express");
const mongoose = require("mongoose");

const User = require("./models/user");

const router = express.Router();

router.post("/signup", (req, res) => {
  const { username } = req.body;

  User.findOne({ username: username })
    .then((existingUser) => {
      if (existingUser) {
        return res.status(400).json({ error: "Username already exists" });
      }
      User.create(req.body)
        .then((user) => res.json(user))
        .catch((err) => res.status(500).json(err));
    })
    .catch((err) => res.status(500).json(err));
});

router.post("/login", async (req, res) => {
  const { username, password } = req.body;
  try {
    const user = await User.findOne({ username: username });
    if (user) {
      if (user.password === password) {
        req.session.username = req.body.username;
        console.log("Session:", req.session);
        res.status(200).json("Success");
      } else {
        res.status(400).json("密码错误");
      }
    } else {
      res.status(404).json("找不到该用户");
    }
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

router.get("/logout", (req, res) => {
  req.session.destroy(() => {
    res.send("退出成功");
  });
});

module.exports = router;

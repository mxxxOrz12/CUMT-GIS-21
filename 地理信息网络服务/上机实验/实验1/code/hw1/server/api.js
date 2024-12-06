/*
|--------------------------------------------------------------------------
| api.js -- server routes
|--------------------------------------------------------------------------
|
*/

const express = require("express");

const myName = "Ma Xiao";
const Story = require("./models/story");
const Comment = require("./models/comment");
const Stars = require("./models/star");

const router = express.Router();

router.get("/stories", (req, res) => {
  Story.find({}).then((storys) => res.send(storys));
});

router.post("/story", (req, res) => {
  if (req.session.username) {
    const newStory = new Story({
      creator_name: req.session.username,
      content: req.body.content,
    });
    newStory.save().then((story) => res.send(story));
  } else {
    res.status(401).json("未登录");
  }
});

router.get("/comment", (req, res) => {
  Comment.find({
    parent: req.query.parent,
  }).then((comments) => {
    res.send(comments);
  });
});

router.post("/comment", (req, res) => {
  const newComment = new Comment({
    creator_name: req.session.username,
    content: req.body.content,
    parent: req.body.parent,
  });
  newComment.save().then((comment) => res.send(comment));
});

router.get("/stars", (req, res) => {
  Stars.find({}).then((stars) => res.send(stars));
});

router.put("/updateStars", (req, res) => {
  Stars.findOneAndUpdate({}, { $inc: { star: 1 } }, { new: true })
    .then((updatedStar) => {
      if (!updatedStar) {
        return res.status(404).send({ message: "Star not found" });
      }
      res.send(updatedStar);
    })
    .catch((error) => res.status(500).send(error));
});

router.all("*", (req, res) => {
  console.log(`API route not found: ${req.method} ${req.url}`);
  res.status(404).send({ msg: "API route not found" });
});

module.exports = router;

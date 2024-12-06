import React, { useState, useEffect } from "react";
import CatHappiness from "../modules/CatHappiness.js";
import { Button, message } from "antd";
import { get, put } from "../../utilities";

import "../../utilities.css";
import "./Profile.css";

const Profile = () => {
  const [stars, setStars] = useState(null);
  const [messageApi, contextHolder] = message.useMessage();

  const success = () => {
    messageApi.open({
      type: "success",
      content: "感谢你的点赞",
    });
    put("/api/updateStars").then(() => {
      console.log("发送成功");
      get("/api/stars").then((Stars) => {
        setStars(Stars[0].star);
      });
    });
  };
  useEffect(() => {
    get("/api/stars").then((Stars) => {
      console.log(Stars);
      setStars(Stars[0].star);
    });
  }, messageApi);

  useEffect(() => {
    document.title = "Profile Page";
    get("/api/stars").then((Stars) => {
      console.log(Stars);
      setStars(Stars[0].star);
    });
  }, []);

  return (
    <>
      {contextHolder}
      <div className="Profile-avatarContainer" onClick={success}>
        <div className="Profile-avatar" />
      </div>
      <h1 className="Profile-name u-textCenter">Xiao Ma &nbsp;&nbsp;&nbsp;(马骁)</h1>

      <hr className="Profile-line" />
      <div className="u-flex">
        <div className="Profile-subContainer u-textCenter">
          <h4 className="Profile-subTitle">关于我</h4>
          <div id="profile-description">
            <p>中国矿业大学2021级GIS专业</p>
            <p> Web开发、GIS开发、SLAM、遥感云计算</p>
          </div>
        </div>
        <div className="Profile-subContainer u-textCenter">
          <h4 className="Profile-subTitle2">Stars</h4>
          <CatHappiness stars={stars} />
        </div>
        <div className="Profile-subContainer u-textCenter">
          <h4 className="Profile-subTitle">个人爱好</h4>
          <div className="Profile-favorite">编程，篮球，游戏</div>
        </div>
      </div>
    </>
  );
};

export default Profile;

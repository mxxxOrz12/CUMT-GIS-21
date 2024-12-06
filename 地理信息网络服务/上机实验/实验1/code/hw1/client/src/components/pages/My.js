import React from "react";
import { GithubOutlined, ZhihuOutlined } from "@ant-design/icons";

import "./My.css";

const My = () => {
  return (
    <div>
      <div className="My-avatar"></div>
      <div className="My-button">
        <a href="https://github.com/mxxxOrz12">
          <GithubOutlined style={{ fontSize: "60px" }} className="My-button-item" />
        </a>
        <a href="https://www.zhihu.com/people/ping-chang-xin-99-56">
          <ZhihuOutlined
            style={{ fontSize: "60px", color: "#1772f6" }}
            className="My-button-item"
          />
        </a>
      </div>
    </div>
  );
};

export default My;

import React from "react";
import { Link } from "react-router-dom";

import "./NavBar.css";

const NavBar = () => {
  return (
    <nav className="NavBar-container">
      <div className="NavBar-title u-inlineBlock">mxxxOrz的个人博客</div>
      <div className="NavBar-right">
        <Link to="/" className="NavBar-link">
          首页
        </Link>
        <Link to="/file" className="NavBar-link">
          文档
        </Link>
        <Link to="/my" className="NavBar-link">
          我的
        </Link>
      </div>
    </nav>
  );
};

export default NavBar;

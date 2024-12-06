import React from "react";
import NavBar from "./modules/NavBar.js";
import { BrowserRouter, Route, Routes, Navigate } from "react-router-dom";
import Feed from "./pages/Feed.js";
import NotFound from "./pages/NotFound.js";
import Profile from "./pages/Profile.js";
import My from "./pages/My.js";
import Signup from "./pages/Signup.jsx";

import "../utilities.css";
import "./App.css";

const App = () => {
  return (
    <BrowserRouter>
      <Routes>
        {/* 独立的登录页面，不包含 NavBar 和 App-container */}
        <Route path="/login" element={<Signup />} />

        {/* 默认重定向到登录页面 */}
        <Route path="/" element={<Navigate to="/login" />} />

        {/* 其他页面包含 NavBar 和 App-container */}
        <Route
          path="*"
          element={
            <>
              <NavBar />
              <div className="App-container">
                <Routes>
                  <Route path="/file" element={<Feed />} />
                  <Route path="/profile" element={<Profile />} />
                  <Route path="/my" element={<My />} />
                </Routes>
              </div>
            </>
          }
        />
      </Routes>
    </BrowserRouter>
  );
};

export default App;

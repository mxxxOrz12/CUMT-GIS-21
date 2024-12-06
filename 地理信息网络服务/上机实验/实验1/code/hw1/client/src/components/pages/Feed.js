import React, { useState, useEffect } from "react";
import Card from "../modules/Card.js";
import { NewStory } from "../modules/NewPostInput.js";
import ReactMarkdown from "react-markdown";
import remarkGfm from "remark-gfm";
import rehypeRaw from "rehype-raw";
import matter from "gray-matter";
import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
import { tomorrow } from "react-syntax-highlighter/dist/esm/styles/prism";

import { get } from "../../utilities";
import { UpCircleOutlined, DownCircleOutlined } from "@ant-design/icons";

import "./Feed.css";
const components = {
  img: ({ node, ...props }) => (
    <img
      {...props}
      style={{
        backgroundRepeat: "no-repeat",
        backgroundSize: "cover",
        width: "100%",
        height: "auto",
      }}
    />
  ),
  code: ({ node, inline, className, children, ...props }) => {
    const match = /language-(\w+)/.exec(className || "");
    return !inline && match ? (
      <SyntaxHighlighter
        children={String(children).replace(/\n$/, "")}
        style={tomorrow}
        language={match[1]}
        PreTag="div"
        {...props}
      />
    ) : (
      <code className={className} {...props}>
        {children}
      </code>
    );
  },
};

const scrollToTop = () => {
  window.scrollTo({ top: 0, behavior: "smooth" });
};
const scrollToBottom = () => {
  window.scrollTo({ top: document.documentElement.scrollHeight, behavior: "smooth" });
};

const Feed = () => {
  const [stories, setStories] = useState([]);
  const [mdContent, setMdContent] = useState(" ");

  useEffect(() => {
    document.title = "News Feed";
    get("/api/stories").then((storyObjs) => {
      let reversedStoryObjs = storyObjs.reverse();
      setStories(reversedStoryObjs);
    });

    fetch("./GNSS复习.md")
      .then((res) => {
        return res.text();
      })
      .then((text) => {
        console.log(text);
        setMdContent(text);
      });
  }, []);

  const addNewStory = (storyObj) => {
    setStories([storyObj].concat(stories));
  };

  let storiesList = null;
  const hasStories = stories.length !== 0;
  if (hasStories) {
    storiesList = stories.map((storyObj) => (
      <Card
        key={`Card_${storyObj._id}`}
        _id={storyObj._id}
        creator_name={storyObj.creator_name}
        content={storyObj.content}
      />
    ));
  } else {
    storiesList = <div>No stories!</div>;
  }
  return (
    <>
      <ReactMarkdown
        children={mdContent}
        rehypePlugins={[rehypeRaw]}
        remarkPlugins={[remarkGfm]}
        components={components}
      />
      <div className="Feed-comment">
        <div>
          <p className="Feed-comment-title">评论区</p>
        </div>
        <NewStory addNewStory={addNewStory} />
        {storiesList}
      </div>
      <div className="Feed-anchor">
        <UpCircleOutlined
          style={{ fontSize: "40px", color: "#49C6F9" }}
          className="anchor"
          onClick={scrollToTop}
        />
        <DownCircleOutlined
          style={{ fontSize: "40px", color: "#49C6F9" }}
          className="anchor"
          onClick={scrollToBottom}
        />
      </div>
    </>
  );
};

export default Feed;

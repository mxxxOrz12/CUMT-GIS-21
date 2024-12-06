import React from "react";

/**
 * Proptypes
 * @param {string} _id of the story
 * @param {string} creator_name
 * @param {string} content of the story
 */
const SingleStory = (props) => {
  return (
    <div className="Card-story">
      <span className="u-bold">{props.creator_name}</span>
      <p className="Card-storyContent">{props.content}</p>
    </div>
  );
};

export default SingleStory;

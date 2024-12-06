import React from "react";
import "./CatHappiness.css";
import { StarOutlined, StarFilled, StarTwoTone } from "@ant-design/icons";
/**
 *
 * Proptypes
 * @param {int} catHappiness is how happy your cat is
 */
const CatHappiness = (props) => {
  console.log(props);
  return (
    <div className="CatHappiness-container">
      <div className="CatHappiness-story">
        <StarTwoTone twoToneColor="#eb2f96" style={{ fontSize: "40px" }} />
        <p className="CatHappiness-stars">{props.stars}</p>
      </div>
    </div>
  );
};

export default CatHappiness;

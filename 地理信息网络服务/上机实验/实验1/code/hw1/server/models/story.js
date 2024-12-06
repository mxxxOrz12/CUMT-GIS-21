const mongoose = require("mongoose");

const StorySchema = new mongoose.Schema({
  creator_name: String,
  content: String,
});

module.exports = mongoose.model("story", StorySchema);

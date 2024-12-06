const mongoose = require("mongoose");

const StarSchema = new mongoose.Schema({
  star: Number,
});
module.exports = mongoose.model("star", StarSchema);

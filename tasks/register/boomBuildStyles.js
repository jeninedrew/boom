module.exports = function (grunt) {
  grunt.registerTask('boomBuildStyles', [
    'sass_globbing:boom',
    'sass:boom',
    'postcss:boom'
  ]);
};

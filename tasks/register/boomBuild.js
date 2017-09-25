module.exports = function (grunt) {
  grunt.registerTask('boomBuild', [
    'boomBuildStyles',
    'boomBuildImages',
    'boomBuildPatternlab'
  ]);
};

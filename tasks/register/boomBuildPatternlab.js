module.exports = function (grunt) {
  if (grunt.file.exists(grunt.config.get('pkg').themePath + '/pattern-lab/')) {
    grunt.registerTask('boomBuildPatternlab', [
      'shell:patternlabComposer',
      'shell:patternlab'
    ]);
  }
  else {
    grunt.registerTask('boomBuildPatternlab', []);
  }
};

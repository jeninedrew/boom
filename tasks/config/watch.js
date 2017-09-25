module.exports = function (grunt) {
  grunt.config.merge({
    watch: {
      boom: {
        files: ['<%= pkg.themePath %>/sass/**/*.scss','<%= pkg.themePath %>/pattern-lab/source/_patterns/**/*.scss'],
        tasks: ['boomBuildStyles'],
      },
      patternlab: {
        files: ['<%= pkg.themePath %>/pattern-lab/source/**/*.twig','<%= pkg.themePath %>/pattern-lab/source/**/*.json','<%= pkg.themePath %>/pattern-lab/source/**/*.yaml','<%= pkg.themePath %>/pattern-lab/source/**/*.yml'],
        tasks: ['shell:patternlab'],
        options: {
          livereload: true
        }
      },
      svgs: {
        files: ['<%= pkg.themePath %>/images/bg/*.svg'],
        tasks: ['boomBuildImages', 'boomBuildStyles'],
      },
    }
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-simple-watch');
}

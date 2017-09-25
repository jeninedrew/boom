# Drupal 8 Theme with Pattern Lab

- [Sass](http://sass-lang.com/)-based 

- Mobile-first responsive approach

- Pattern Lab's component-based approach

## The Setup 

- [composer](https://getcomposer.org)
- [drush](http://www.drush.org/en/master/)
- [grunt](https://gruntjs.com/)

## Quick Start

- Run Grunt build task `grunt` to compile Sass , compile the CSS/Pattern Lab files and watch PAttern Lab files for changes.

## Compiling Sass

[LibSass](http://sass-lang.com/libsass) is required to compile the Sass into
CSS. boom includes Grunt tasks to compile the CSS/Pattern Lab files and to
watch them for changes. To use these tasks, run the following NPM command in
the theme folder (Windows users may need to include the `--no-bin-links` flag at
the end of the command).

```
npm install
```

To run the Grunt build task, run:

```
grunt
```

## Sass/Grunt dependencies

* [Breakpoint](http://breakpoint-sass.com): Easy to write media queries.

* [Sass](http://sass-lang.com): CSS on steroids. Adds nested rules, variables,
mixins, selector inheritance, and more.

* [Sass Globbing](https://github.com/DennisBecker/grunt-sass-globbing): Adds glob-
based imports to Sass.

* [SVG2PNG](https://github.com/dbushell/grunt-svg2png): Rasterizes SVG to PNG images using PhantomJS.

* [Autoprefixer](https://github.com/postcss/autoprefixer): Adds necessary browser CSS property prefixes during Sass compilation.

## Pattern Lab




## Notes

- Built with [Gesso starter theme](https://www.drupal.org/project/boom) and [Twig boom StarterKit for Drupal](https://github.com/forumone/starterkit-twig-drupal-boom) (installed with Pattern Lab).



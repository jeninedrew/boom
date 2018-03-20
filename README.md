# Drupal 8 Theme with Pattern Lab

- [Sass](http://sass-lang.com/)-based 

- Mobile-first responsive approach

- Pattern Lab's component-based approach

## The Setup 

- [composer](https://getcomposer.org)
- [drush](http://www.drush.org/en/master/)
- [grunt](https://gruntjs.com/)

## Quick Start

- Run Grunt build task `grunt` to compile Sass , compile the CSS/Pattern Lab files and watch Pattern Lab files for changes.

- Pattern Lab site: capr.diggity/themes/boom/pattern-lab/public/index.html

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

Uses Drupal standard edition of Pattern Lab and [the Gesso Twig starter kit](https://github.com/forumone/starterkit-twig-drupal-gesso), found in a subdirectory of Gesso called 'pattern-lab'.

After install, others cloning the repo need to run `composer install` to install dependencies.

### One line start

This will compile PL and watch for changes while running the local server:

    composer start --timeout=0

### Generate Pattern Lab

To generate the front-end for Pattern Lab type:

    php core/console --generate

### Start a server to view Pattern Lab

You can use PHP's built-in web server to review your Pattern Lab project in a browser. In a separate window type:

    php core/console --server

Then open [http://localhost:8080](http://localhost:8080) in your browser.

### Updating Pattern Lab

    composer update

## Notes

- Built with [Gesso starter theme](https://github.com/forumone/gesso) and [Twig Gesso StarterKit for Drupal](https://github.com/forumone/starterkit-twig-drupal-gesso) (installed with Pattern Lab).

# Integrated Modular Design

Read the [case study](https://frances.ink/portfolio/modular-design.html). 
<br> 

<p align="center">
  <img src="https://frances.ink/assets/img/modular-design/flow.png" />
</p>

## Summary

A Drupal 8 theme enhanced with an integrated version of Pattern Lab's component-based design system. The theme enables designers, developers and clients to collaborate using reusable UI elements and centralized sources for easy modification across patterns. Interactive designs mean components are quickly optimized and tested for responsiveness, accessibility and performance.

- Strategy, Design and Development
- Drupal 8 Theme and Pattern Lab
- Integrated Design System
- Content Strategy
- HTML, CSS, Sass, Grunt, JS, MySQL

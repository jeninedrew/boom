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
    
# Case Study

Read the [case study](https://frances.ink/portfolio/modular-design.html). 

## Integrated Modular Design

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

## Design Highlights

### Modular Design

Pattern Lab, an open-source tool for building UI design systems, relies on smaller design components combined to create page sections and templates.

The modular system reduces complexity while enforcing standardized styles, enabling designers and developers to effectively communicate and focus on optimization including accessibility and performance goals.

Pattern Lab provides a way to describe the stitched together patterns so they can easily be referenced and updated. Reducing complexity ensures a maintainable and future-friendly system.

Pattern Lab also provides ways to efficiently communicate with the client using interactive wireframes that integrate seamlessly into a component-based workflow. Clients are able to interact with individual components and low-fidelity versions of final pages, supporting an iterative design process.

### Responsive Design

Responsive websites focus on delivering thoughtful user experiences regardless of environment, bandwidth or specific user needs.

Integrating Pattern Lab means designs move quickly to the browser and Drupal theme where they can be tested and optimized, supporting a mobile-first responsive approach.

## Content Strategy

### Create Once, Publish Everywhere

Creating content once and publishing in multiple places disseminates content without overly burdening the creator.

The content strategy informs the design system. Embracing a content-first approach, content and organizational goals are assessed during the planning phase to ensure the design approach addresses existing needs.

Members with different roles contribute and curate featured content. The content strategy engages contributors while allowing privileged users to curate highly visible content. Based on the user’s permissions, instructions and resources for managing content are shown.

A custom content type provides the primary admin interface for contributing content including variations and associated media. Content is promoted across the site using the same interface. Managing content in one place reduces complexity while leveraging valuable contributions. Articles are promoted with minimal effort and searchable archives are preserved.

Roles determine access to privileged features like promoting articles. The content strategy engages contributors while allowing privileged users to curate highly visible content.

Custom admin interfaces are displayed based on an assigned role. To increase engagement, adding content for users with restricted access is straightforward. Users with advanced access are trained to navigate additional options allowing them to strategically feature articles and media throughout the site.

## Technical Details

### Integrated Design System

The theme is built on the Gesso Drupal 8 starter theme which integrates a version of Pattern Lab, automatically updating modified patterns across the site.

Integrating Pattern Lab eliminates the need to maintain separate design systems, saving time and giving contributors immediate feedback.

Drupal 8 improvements include a simplified theme layer and the introduction of the Twig templating language. Gesso complies with Drupal’s CSS best practices, using SMACSS to organize styles. The theme follows the same standards for consistency and clarity. Together, Drupal 8 and Gesso provide a semantic and organized foundation.

Grunt compiles Sass and watches Pattern Lab files for changes. Flexbox is used for layout.

<br> 
<p align="center">
    <img src="https://frances.ink/assets/img/modular-design/screen.jpg" />
</p>


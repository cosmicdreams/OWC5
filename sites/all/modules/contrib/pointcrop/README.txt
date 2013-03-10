Pointcrop
=====================

The pointcrop module allows you to set focus points for images uploaded using
Drupal's image fields.
The module also provides image effects for "Pointcrop crop" and "Pointcrop
scale and crop", for focus point based cropping via Drupal's image style
system.

This way, whenever an image is cropped to any dimensions, the focus point is
always in the centre (or as close as possible) of the cropped image.

Pointcrop cropping gives great image cropping results in all cases but is
particularly useful in situations where images need to be shown at different
sizes and/or different orientations in different places.
In those cases, alternative methods such as manual cropping might not suit all
the applications of a particular image.

In addition to the image effects provided by the module, there is also a
jQuery plugin that can be used to crop images on the front end, based on the
focus points set using the pointcrop drupal module.

This module does not currently have any out of the box implementations of
this jQuery plugin, but there is potential for it to in the future.


Requirements
=====================

 * Image module (drupal core)
 * (optional) jQuery PointCrop: http://www.pointcrop.com


Installation
=====================

Enable the Pointcrop module as per
http://drupal.org/documentation/install/modules-themes/modules-7

If you are also using the jQuery PointCrop plugin to crop images on the front
end, you will also have to download and extract the plugin.
It is recommended in this case that you use the Libraries API module 
(http://drupal.org/project/libraries) and extract the plugin to
sites/all/libraries/jquery.pointcrop


Configuration
=====================

Permissions
-------------
Set permissions for the "Set pointcrop focus point" permission, which allows
to set the focus point when adding / editing content with image fields.

Field set-up
-------------
 1. Go to the setting page of any image fields you want to use pointcrop with.
 2. In the "Pointcrop focus settings" section, check the "Enable pointcrop"
checkbox.
 3. In the "Pointcrop focus settings" section, select an image style to use
when showing the image with the image field so users can select the focus point.
Selecting an image style is optional but recommended.

Image styles
-------------
To use the "Pointcrop crop" and "Pointcrop scale and crop" image styles:
 1. Add a new image style at admin/config/media/image-styles/add
 2. Add a new "Pointcrop Scale And Crop" or "Pointcrop Crop" effect.
 3. Enter the required dimensions and save.


Support
=====================

If you wish to report any bugs or request new features or support for the
pointcrop Drupal module please use the issue queue on drupal.org at
http://drupal.org/project/issues/pointcrop

If you wish to report any bugs or request new features or support for the
pointcrop jQuery plugin, please use the issue queue on github.com at
http://github.com/OxideInteractive/pointcrop/issues


Maintainers
=====================

  Oxide Interactive (http://drupal.org/user/136500)

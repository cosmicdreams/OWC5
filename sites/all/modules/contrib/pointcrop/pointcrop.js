/**
 * @file
 * Javascript for the pointcrop module.
 */

(function($) {

  var valToSel = function(val) {
    var sel = val.split(',');
    if (sel.length != 2) {
      return null;
    }

    for (var i = 0; i < 2; i++) {
      var v = Number(sel[i]);
      if (isNaN(v) || v < 0 || v > 1) {
        return null;
      }
    }

    return sel;
  };

  var selToVal = function(sel) {
    return (sel) ? sel.join(',') : '';
  };

  var roundNumber = function (num, dec) {
    return Math.round(num * Math.pow(10, dec)) / Math.pow(10, dec);
  }

  /**
   * Drupal behavior for pointcrop.
   */
  Drupal.behaviors.pointcrop = {
    attach: function(context) {
      $('.pointcrop.focus-box', context).once('pointcrop', function() {
        var $this = $(this);
        var imgWrapper = $('> .img-wrapper', $this);
        var img = $('> .img-wrapper > img', $this);
        var input = $('input.pointcrop', $this.parent());
        var fieldName = input.attr('name').replace(/^([a-z0-9_]+)\[.+$/, '$1');
        var settings = Drupal.settings.pointcrop;
        img.css('display', 'block');

        var appendMarkerImage = function(x, y) {
          // Remove existing image if there is one.
          $('#pointcrop-focus-point-dot').remove();

          // Generate marker image.
          var marker = $('<img>');
          marker.css('top', y);
          marker.css('left', x);
          marker.css('position', 'absolute');
          marker.attr('id', 'pointcrop-focus-point-dot');
          marker.attr('src', Drupal.settings.basePath + settings.path + '/dot.png');

          // Add marker.
          marker.appendTo(imgWrapper);
        }

        // Handle clicking the image.
        imgWrapper.click(function(e) {
          e.preventDefault();
          // Remove existing image if there is one.
          $('#pointcrop-focus-point-dot').remove();
          // Locate the click relative to the image.
          var offset = $(this).offset();
          var x = e.pageX - offset.left;
          var y = e.pageY - offset.top;

          // Append marker, on centre of image.
          appendMarkerImage(x - 5, y - 5);
          // Determine ratio based on image dimensions.
          // Image dimensions depends on imagecache preset so we get them here.
          var width = imgWrapper.children('img').width();
          var height = imgWrapper.children('img').height();
          // Set field value.
          input.val(selToVal([roundNumber(x / width, 8), roundNumber(y / height, 8)]));
        });

        input.change(function() {
          var val = input.val();
          if (val) {
            var coords = valToSel(val);
            // Image dimensions depends on imagecache preset so we get them here.
            var width = imgWrapper.children('img').width();
            var height = imgWrapper.children('img').height();
            // Append marker, on centre of image.
            appendMarkerImage((coords[0] * width) - 5, (coords[1] * height) - 5);
          }
          else {
            // Remove existing image if there is one.
            $('#pointcrop-focus-point-dot').remove();
          }
        });
        // Set an image on load in case there is a value already.
        // Wait until the image has loaded or dimensions may be inaccurate.
        imgWrapper.children('img').load(function () {
          input.change();
        });
      });
    }
  };

})(jQuery);

/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

$(function(){
	//Main Menu things
	$('#navigation nav li').hover(function(){
		if(!$(this).hasClass('active-trail')){
			$(this).find('.menu').slideDown();
			console.log($(this).attr('class'));
		}
	}, function(){
		if(!$(this).hasClass('active-trail')){
			$(this).find('.menu').hide();
		}
	});

});

})(jQuery, Drupal, this, this.document);

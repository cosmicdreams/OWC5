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
	var windowSize;

	windowSize = $(window).width();

	//Main Menu things
	$('#navigation nav li').hover(function(){
		if(!$(this).hasClass('active-trail') && windowSize > 500){
			$(this).find('.menu').slideDown();
		}
	}, function(){
		if(!$(this).hasClass('active-trail') && windowSize > 500){
			$(this).find('.menu').hide();
		}
	});

	console.log(windowSize);

	//Mobile Shit
	if(windowSize < 500){
		$('#navigation nav li').bind('click', function(e){
			e.preventDefault();

			if($(this).find('.menu').length > 0 && !$(this).find('.menu').hasClass('active')){
				//first hide
				$('.menu.active').slideUp();
				$('.menu').removeClass('active');
				//then show
				$(this).find('.menu').addClass('active');
				$(this).find('.menu').slideDown();
			}
		});
	}
});

})(jQuery, Drupal, this, this.document);

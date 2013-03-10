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
		var mobileNav = function(e){
			e.preventDefault();
			if($(this).find('.menu').length > 0 && !$(this).find('.menu').hasClass('active')){
				$('#navigation nav li').removeClass('minus');
				$(this).addClass('minus');
				//first hide
				$('.menu.active').slideUp();
				$('.menu').removeClass('active');
				//then show
				$(this).find('.menu').addClass('active');
				$(this).find('.menu').slideDown();				
			}
		};
		var responsiveMenus = function(){
			if(windowSize < 420){
				$('#navigation nav li').bind('click', mobileNav);
			} else {
				$('#navigation nav li').unbind('click', mobileNav);
				$('#navigation nav li').removeClass('minus');
				$(this).find('.menu').hide();
			}
			windowSize = $(window).width();
		}

		//Main Menu things
		$('#navigation nav li').hover(function(){
			if(!$(this).hasClass('active-trail') && windowSize > 420){
				$(this).find('.menu').slideDown();
			}
		}, function(){
			if(!$(this).hasClass('active-trail') && windowSize > 420){
				$(this).find('.menu').hide();
			}
		});

		console.log(windowSize);

		//Mobile Shit
		responsiveMenus();
		$(window).resize(responsiveMenus);

		//$('.form-select').hide();
		
		$('select').each(function(){
			var id = $(this).attr('id');
			var optionSelected = $(this).find(':selected').text();
			$(this).css('background-color','blue');
			$(this).after('<ul class="styledSelect_list styledSelect_list-'+id+' styledSelect_list-isHidden"></ul>');
			$(this).after('<div class="styledSelect_optionSelected styledSelect_optionSelected-'+id+'"><span class="styledSelect_optionText">'+optionSelected+'<span></div>');


			$(this).find('option').each(function(){
				var val = $(this).text();
				$('.styledSelect_list-'+id+'').append('<li class="styledSelect_option">'+val+'</li>');
			});
		});
		$('.styledSelect_optionSelected').click(function(){
			$(this).next('.styledSelect_list').toggleClass('styledSelect_list-isHidden');
		});

		$('.styledSelect_option').click(function(){
			var text = $(this).text();
			var parentList = $(this).parent()
			var parentOptionSelected = parentList.prev();
			var parentSelect = parentOptionSelected.prev();
			$(parentList).toggleClass('styledSelect_list-isHidden');
			parentOptionSelected.text(text);
			$(parentSelect).find('option').filter(function() {
			    return $(this).text() == text; 
			}).attr('selected', true);

		});


	});

})(jQuery, Drupal, this, this.document);

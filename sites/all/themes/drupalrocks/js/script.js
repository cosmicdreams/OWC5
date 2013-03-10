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
		$('#page').before('<div style="color:white;background-color:black;padding:10px 15px;position:fixed;left:0;bottom:0">Script loaded</div>')
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

		/*
		$('select').each(function(){
			var index = $(this).index();
			$(this).css('background-color','blue');
			$(this).data('index',index);
			$(this).after('<div class="'+select+'-index"><p>blahblah</p></div>')
		});
		*/
	});


})(jQuery, Drupal, this, this.document);

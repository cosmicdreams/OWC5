(function ($, Drupal, window, document, undefined) {

	$(function(){
		//get the images
		$('#block-views-rotator-view-block').before('<div class="rotator"></div>');
		$('.field-name-field-slide-image img').each(function(){
			var imghref = $(this).attr('src');
			$('.rotator').append('<div class="item"> \
		            <img src="'+imghref+'" /> \
		            <div class="blurb"> \
		              <div class="tab">2013</div> \
		              <h2>Annual Conference</h2> \
		              <a href="">Learn More</a> \
		            </div> \
		          </div>')
		});
		$('#block-views-rotator-view-block, .node-slideshow').remove();

		//Rotator Blurbs
		var blurb = function(item){
			item.find('.blurb').animate({
				minWidth: 280
			}, 400, function(){
				item.find('.blurb .tab').animate({
					height: 24,
					opacity: 1,
					top: -26
				}, 400);
				item.find('.blurb a').fadeIn(333);
			});
		}
		var blurbReset = function(){
			$('.blurb').css({width:0});
			$('.blurb a').hide();
			$('.blurb .tab').css({height:0,opacity:0,top:0});
		}
		//Setup the rotator
		blurb($('.rotator .item:first'));
		$('.rotator').after('<ul class="rotator-pager clearfix"></ul>');
		var i=0;
		$('.rotator .item').each(function(){
			i++;
			$(this).attr('rel', i);
			$('ul.rotator-pager').append('<li rel="'+i+'"><span></span></li>');

			var imgH = $(this).find('img').height();
			var rotH = $('.rotator').height();

			if(imgH > rotH){

			}
		});
		$('.rotator .item:first').addClass('active');
		//Setup the pager
		$('ul.rotator-pager li:first').addClass('active');
		$('ul.rotator-pager li').live('click', function(){
			clearInterval(rotatorInterval);
			$('.rotator .item').removeClass('prev');

			var curRel = $(this).attr('rel');

			if(!$(this).hasClass('active')){
				$('ul.rotator-pager li').removeClass('active');
				$(this).addClass('active');

				$('.rotator .item[rel="'+curRel+'"]').addClass('next');
				var nextRel = $('.rotator .item[rel="'+curRel+'"]').attr('rel');

				blurbReset();
				$('.rotator .item.active .blurb, .rotator .item.next .blurb').hide();
				
				// starting animation
				$('.rotator .item.active').stop().animate({
					width: "50%",
					top: "15%"
				}, 600, function(){
					$('.rotator .item.active').addClass('prev');
					$('.rotator .item').removeClass('active');
					$('.rotator .item.next').addClass('active');
					$('.rotator .item').removeClass('next');
				});
				$('.rotator .item.next').stop().animate({
					width: "50%",
					left: "50%",
					top: "15%"
				}, 600);
				// ending animation
				$('.rotator .item[rel="' +nextRel+ '"]').animate({
					width: "100%", height: "100%",
					top:"0%",
					left: "0%"
				}, 600, function(){
					$('.rotator .item.active .blurb').show();
					blurb($('.rotator .item[rel="' +nextRel+ '"]'));

				});
				$('.rotator .item[rel="' +actRel+ '"]').animate({
					width: "100%", height: "100%",
					top:"0%",
					left: "0%"
				}, 600, function(){
					$('.rotator .item').removeClass('prev');
				});
			}

			rotatorInterval;

		});
		//Rotator Function
		var rotator = function(){
			var actRel = $('.rotator .item.active').attr('rel');
			$('ul.rotator-pager li').removeClass('active');
			//$('.rotator .item').removeClass('prev')
			
			if($('.rotator .item.active').next().length > 0){
				$('.rotator .item.active ').next('.item').addClass('next');
				blurbReset();
				$('.rotator .item.active .blurb, .rotator .item.next .blurb').hide();
				var nextRel = $('.rotator .item.next').attr('rel');
				
				// starting animation
				$('.rotator .item.active').animate({
					width: "50%",
					top: "15%"
				}, 600, function(){
					$('.rotator .item.active').addClass('prev');
					$('.rotator .item').removeClass('active');
					$('.rotator .item.next').addClass('active');
					$('.rotator .item').removeClass('next');
				});
				$('.rotator .item.next').animate({
					width: "50%",
					left: "50%",
					top: "15%"
				}, 600);
				// ending animation
				$('.rotator .item[rel="' +nextRel+ '"]').animate({
					width: "100%",
					top:"0%",
					left: "0%"
				}, 600, function(){
					$('.rotator .item.active .blurb').show();
					blurb($('.rotator .item[rel="' +nextRel+ '"]'));
					$('ul.rotator-pager li[rel="' +nextRel+ '"]').addClass('active');

				});
				$('.rotator .item[rel="' +actRel+ '"]').animate({
					width: "100%",
					top:"0%",
					left: "0%"
				}, 600, function(){
					$('.rotator .item').removeClass('prev');
				});

			} else {
				$('.rotator .item:first ').addClass('next');
				blurbReset();
				$('.rotator .item.active .blurb, .rotator .item.next .blurb').hide();

				var nextRel = $('.rotator .item.next').attr('rel');
				
				// starting animation
				$('.rotator .item.active').animate({
					width: "50%",
					top: "15%"
				}, 600, function(){
					$('.rotator .item.active').addClass('prev');
					$('.rotator .item').removeClass('active');
					$('.rotator .item.next').addClass('active');
					$('.rotator .item').removeClass('next');
				});
				$('.rotator .item.next').animate({
					width: "50%",
					left: "50%",
					top: "15%"
				}, 600);
				// ending animation
				$('.rotator .item[rel="' +nextRel+ '"]').animate({
					width: "100%",
					top:"0%",
					left: "0%"
				}, 600, function(){
					$('.rotator .item.active .blurb').show();
					blurb($('.rotator .item[rel="' +nextRel+ '"]'));
					$('ul.rotator-pager li[rel="' +nextRel+ '"]').addClass('active');
				});
				$('.rotator .item[rel="' +actRel+ '"]').animate({
					width: "100%",
					top:"0%",
					left: "0%"
				}, 600, function(){
					$('.rotator .item').removeClass('prev');
				});
			}
		};
		var rotatorInterval;
		rotatorInterval = setInterval(rotator, 7500);
    
	});
})(jQuery, Drupal, this, this.document);
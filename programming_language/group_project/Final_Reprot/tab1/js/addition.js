
$(document).ready(function() {
	$("#tabs-1").slideUp();
	$("#tabs-2").slideUp();
	$("#tabs-3").slideUp();
	$("#tabs_1").click(function(){
		$("#tabs-1").slideDown();
		$("#tabs-2").slideUp();
		$("#tabs-3").slideUp();
	});
	$("#tabs_2").click(function(){
	$("#tabs-2").slideDown();
	$("#tabs-1").slideUp();
	$("#tabs-3").slideUp();
	});
	$("#tabs_3").click(function(){
		$("#tabs-3").slideDown();
		$("#tabs-2").slideUp();
		$("#tabs-1").slideUp();
	});
	
	});
$(document).ready(function(){
	$(".paragra_his").hide();
	$(".paragra_intro").hide();
	$(".introduction").click(function(){
		$(".paragra_intro").show();
	});
	$(".history").click(function(){
		$(".paragra_his").show();
	});
});

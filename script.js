/**
 * @author Rukmal Weerawarana
 *
 * @description Accompanying JS for my Project Euler solutions website:
 *              http://rukmal.github.io/Project-Euler-Solutions
 */


// Constants
var languages = {
	"c": "C",
	"py": "Python",
	"js": "JavaScript",
	"java": "Java"
}
var popups = [];

/**
 * Function to decode Base64 string
 * @param  {String} encodedString Encoded Base64 string
 * @return {String}               Decoded Base64 string, as ASCII
 */
function decode (encodedString) {
	var decodedString = '';
	try {
		// Default JS Base64 decoding function
		decodedString = atob(encodedString);
	} catch (err) {
		if (err.name === 'InvalidCharacterError') {
			decodedString = 'Internal ERR: Invalid Base64 input.';
		} else {
			decodedString = 'ERR: Your browser does not support Base64 decoding. Please upgrade your browser and try again later.';
		}
	}
	return decodedString;
}

function setPopupHTML (questionNumber) {
		var filename = data[solution].name;
		$.get(apiBaseURL + solutionsLocation + filename, function (codedata) {
			var questionNumber = codedata.name.split('.')[0];
			var language = languages[codedata.name.split('.')[1]];
			console.log(language);
		});
}

function getItemHTML (name) {
	var problemNumber = name.split('.')[0];
	popups.push('#popup' + problemNumber);
	var itemHTML = '<div class="col-md-4"><p align="center" class="bodytext" id="p' + problemNumber + '"><a href="#" class="question" data-toggle="modal" data-target="#popup' + problemNumber + '">Problem ' + problemNumber + '</a></p></div>'
	return itemHTML;
}

var solutionsLocation = 'solutions/';
var apiBaseURL = 'https://api.github.com/repos/rukmal/Project-Euler-Solutions/contents/';

$.get(apiBaseURL + solutionsLocation, function (data) {
	if (data === null) {
		console.log('Internal ERR: Error fetching data from GitHub.');
	}
	for (var solution in data) {
		var itemHTML = getItemHTML(data[solution].name);
		$('#solutionslist').append(itemHTML);
	}
});

$('#solutionslist').on('click', '.question', function () {
	console.log('click');
});
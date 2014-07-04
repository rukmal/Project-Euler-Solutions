/**
 * @author Rukmal Weerawarana
 *
 * @description Accompanying JS for my Project Euler solutions website:
 *              http://rukmal.github.io/Project-Euler-Solutions
 */


// Constants
var languages = {
	"c": "c",
	"py": "python",
	"js": "javascript",
	"java": "java"
}
var apiBaseURL = 'https://api.github.com/repos/rukmal/Project-Euler-Solutions/contents/';
var solutionsLocation = 'solutions/';

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

/**
 * Function to create HTML to be inserted in the list
 * @param  {String} name Name of the question
 * @return {String}      HTML to be inserted into the DOM
 */
function getItemHTML (name) {
	var problemNumber = name.split('.')[0];
	var extension = name.split('.')[1];
	var language = languages[extension];
	var itemHTML = '<div class="col-md-4"><p align="center" class="bodytext"><a href="#" class="question" data-toggle="modal" data-target="#popup" question-number="' + problemNumber + '" language="' + language + '" filename="' + name + '">Problem ' + problemNumber + '</a></p></div>'
	return itemHTML;
}

/**
 * Function to create HTML for modal title
 * @param  {String} question Question number
 * @return {String}          HTML to be inserted into the DOM
 */
function getTitleHTML (question) {
	var titleHTML = '<h4 class="modal-title">Problem ' + question + '</h4>'
	return titleHTML;
}

/**
 * Function to create HTML for the code block
 * @param  {String} code     The actual code
 * @param  {String} language Language that the code is written in
 * @return {String}          HTML to be inserted into the DOM
 */
function getCodeHTML (code, language) {
	var codehtml = '<pre class="  language-' + language + '"><code class="  language-' + language + '">' + code + '</code></pre>';
	return codehtml;
}

// Populating the list 

$.get(apiBaseURL + solutionsLocation, function (data) {
	if (data === null) {
		console.log('Internal ERR: Error fetching data from GitHub.');
	}
	for (var solution in data) {
		var itemHTML = getItemHTML(data[solution].name);
		$('#solutionslist').append(itemHTML);
	}
});

// Changing the modal HTML accordingly if it is clicked on
// Doing it this way minimizes API calls, and reduces the chances of hitting
// the hourly limit

$('#solutionslist').on('click', '.question', function () {
	var question = $(this).attr('question-number');
	var filename = $(this).attr('filename');
	var language = $(this).attr('language')
	$('#question-title').empty();
	var titleHTML = getTitleHTML(question);
	$('#question-title').append(titleHTML);
	// grabbing the code from the github api
	$.get(apiBaseURL + solutionsLocation + filename, function (codedata) {
		if (codedata === null) {
			console.log('Internal ERR: Error fetching code from GitHub.');
		}
		var code = decode(codedata.content);
		var codeHTML = getCodeHTML(code, language);
		$('.modal-body').empty();
		$('.modal-body').append(codeHTML);
	});
});
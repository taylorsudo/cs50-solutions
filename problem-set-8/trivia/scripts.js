// Run script once DOM is loaded
document.addEventListener('DOMContentLoaded', function() {

    // When correct answer is clicked, change colour to green
    let correct = document.querySelector('.correct');
    correct.addEventListener('click', function() {
        correct.style.backgroundColor = 'rgba(0, 255, 0, 0.6)';
        document.querySelector('#feedback1').innerHTML = 'Correct!';
    });

    // When any incorrect answer is clicked, change colour to red
    let incorrects = document.querySelectorAll('.incorrect');
    for (let i = 0; i < incorrects.length; i++) {
        incorrects[i].addEventListener('click', function() {
            incorrects[i].style.backgroundColor = 'rgba(255, 0, 0, 0.6)';
            document.querySelector('#feedback1').innerHTML = 'Incorrect!';
        });
    }

    // Check free response submission
    document.querySelector('#check').addEventListener('click', function() {
        let input = document.querySelector('input');
        if (input.value.toLowerCase() === '1997') {
            input.style.backgroundColor = 'rgba(0, 255, 0, 0.6)';
            document.querySelector('#feedback2').innerHTML = 'Correct!';
        } else {
            input.style.backgroundColor = 'rgba(255, 0, 0, 0.6)';
            document.querySelector('#feedback2').innerHTML = 'Incorrect';
        }
    });
});

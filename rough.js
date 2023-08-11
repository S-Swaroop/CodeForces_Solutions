
function reverse(word) {
    const n = word.length; 
    let reversedWord = "";
    for (let i = n - 1; i >= 0; i--) {
        reversedWord += word[i];
    }
    return reversedWord;
}

async function delay(delayTime) {
    return new Promise(resolve => {
        setTimeout(() => { resolve() }, delayTime);
    });
}


(async () => {
    console.log(a);
    var a = 10;
})();
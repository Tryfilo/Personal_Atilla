    // This is where a counter value is created
    let counter = 1;
    // This is where an interval is created
    setInterval(() => {
        // This adds 1 to the counter value
        counter++;
        // This is where the counter value is checked to see if the 1 second period has passed so the page can get
        // automatically reloaded after every second
        if (counter > 1) location.reload();
    }, 1000); // This is the amount of milliseconds the interval is set at
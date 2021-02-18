# TemperatureCompensatedClockARDUINO

Try to compensate the temperature /frequency deviation on a Arduino 
Main goal to make a clock with extreme precision


From the typical variation curve of a crystal, I simplified the intervale of temperatures 
where I live to a function of a line with a slope by the function: 

y=0.29x-7.3

the I assume the same temp. in one minute and add the microseconds of deviation for that minute, and so on.

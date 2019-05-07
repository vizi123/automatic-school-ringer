# automatic-school-ringer
how i made this / story: "smart" governants => chaos in (some) schools due to the removal of the service shift for highschool students that used to trigger the saving bell every day. at that moment, not many schools had an automatic ringer which costed at the time of writing around 300 euros.

because i like programming & messing up with random hardware & creating stuff from scratch i volunteered to build a "thing" in ~3 days which would ring so the ETERNAL FRENCH CLASSES could not eat any more of the short break time.

the bell in my school is triggered by a "light switch" (https://images.app.goo.gl/EwDriSqizbXDUWe29) that would auto-release itself after you take your had off it (i dont know how its called... light switch with a spring inside at one end? ).
into the light switch were inserted 2 wires -  hot wire and a ground one; 

connect these 2 wires => bell rings;

disconnect there 2 wires => nothing

=> we have a "how to turn on a lightbulb with arduino + relay tutorial" youtube situation. hope you got the idea.

i added 2 more wires between the relay and the already existent switch. in case something goes wrong with my device, at least i can trigger with shame the bell using the "light switch".


software:
because i wanted/had to build this in one day, i did not bother with a RTC as i could not find any functional one in the entire city in that day. it measures the time using millis() function and storing the time, minutes, hours and the current date in 4 variables. set up the clock once and hope for the best that it runs as long as possible. losing power would result in resetting the date/time to 00:00, monday. the device has buttons so anyone can set up the clock manually in case of a power outage (or if anyone pulls the charger out of the socket........). 

Note: during the 1 year functioning period, i had some issues at the beggining (explained in the hardware section). just a passionate physics (+robotics) teacher bothered setting the time in case of a power outage / time freezing case... so a RTC would be a very welcomed module.

hardware:
-arduino uno
-mullie function shield (with a 4 digit display for the time and buttons to set the time + day)
-few buttons and switches (for manual / auto mode - useful for exam days, holydays; normal/long classes, and a button to trigger the bell manually, like you would do with the "light switch")
-leds for idicating the day 
-bad looking, kinda bulky housing.
--5V were not sufficient. the clock would freeze from time to time, causing me to go and commit a "ring" of shame during the classes/breaks. with a 9V charger it works just fine, no random freezes so far during a ~6 months period.--



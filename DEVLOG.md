# Of Glass And Steel - Devlog
### Friday, April 26, 11:16pm
Upon getting back to it after a 2-months break, I reconsidered all
 of my programming projects, and figured this one could work. So I
 had to give it a fair attempt.\
It's quite a commitment, but I want to succeed in my creative
 endeavours at some point. Now is my chance to give it a go.\
I'm emptying OGNS' repo and starting anew, using the SDL library
 this time.\
I'm chosing this over an engine because I just have to do it all
 myself - I don't want to have black boxes of functionalities I
 don't understand the implementation of everywhere, I don't want to
 get clumsy with them, and I don't want an oversized, slow or
 complicated program at the end.\
Once I have a good basis, I'll find an artist to work with me on
 the project.\
**23:54:** Hello world\
**01:59:** First set of 4-7 test tiles\
The graphics seem to have to be small in order to fit a full map in
 a decently sized window, or to make a 15' fullscreen challenging.\
**04:39:** Basic resizable title menu displaying\
I was too excited to sleep.\
**06:43:** I couldn't sleep at all\
**08:49:** Polishing the title menu\
**17:09:** I could sleep 3h\
Start of complexity: moved the title menu business to its own files.
 I need to refactor the code in order to create more menus.
### Monday, April 29
**22:19:** I've been thinking about making the menus correctly or
 just skipping that part in order to make a fast prototype. I was
 rather distressed about the matter, also recovering from having
 skipped a night of sleep. Decided I'm capable of making those
 menus, so I'll go for making them. We'll see where it takes me.\
I know that it doesn't make much sense in theory - and it's boring
 to make. In my idea, I want to implement the game linearly so that
 I don't miss anything, no part gets overlooked and brings problems
 later, or implementing the missing parts turns into a headache
 because the program has no room for them. I don't want my early
 game to look like a mess or be impenetrable in how it works if I
 can get it tested by alphas also.\
I'm also coincidentally not doing very well these days.\
### Tuesday, April 30
Now that I've recovered and am feeling a slightly better, about the
 menus, I figure there aren't that many and they include a variety
 of functionalities, so it would be more of a headache to try to make
 a system that would generate menus based on menu information, than
 to just make each of them by hand individually.\
I'd never thought menus could be a source of headache.\
Actually, now that I think of it, having the data in data files or
 hardcoded in, there is virtually no difference between the two.
 Those menus are going to take me to the end of the world.\
It's a bit of a new thing for me since when programming for the
 terminal, there would be no such complicated nonsense to implement.
 Originally OGNS was supposed to be for the terminal. I changed my
 mind as I was looking into my different projects, because I
 thought, this is too bad this game is for the terminal, because it
 could meet actual success. And it would be a real hassle to make a
 dual version.\
**20:55** Fell all of the menu stuff into generic functions, except
 for loading assets, which is the last code specific to a menu. Now
 I can add menu details in, through adding them to my structures and
 handling them in my generic functions.\

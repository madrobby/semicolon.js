# Semicolon.js — a more secure and reliable Vapor.js

Semicolon.js is a much more secure, stable and reliable alternative to 
<a href="http://vaporjs.com/">Vapor.js</a>.


## Build:

After much discussion, it became clear that to support this library far into the
future, we would need to abstract the requirements into its own language, which
can be compiled down to different languages.

Currently the compiler generates valid code for JavaScript and CoffeeScript, but
could easily be extended to support additional languages.

The compiler can be build with:

```
make
```

It produces the `semiscriptc` tool, which can then be used to compile SemiScript
source. These source files typically have the `.semi` extension.

JavaScript:

```
./semiscriptc -js semicolon.semi
;
```

CoffeeScript:

```
./semiscriptc -cs semicolon.semi

```

Beatiful.

Finally, a convenience task is available to produce products for both JavaScript
_and_ CoffeeScript:

```
make distbuild
```


## Usage: 
```html
<script src="semicolon.js"></script>
```

Alternatively, inline the whole code, like this:

```html
<script>;</script>
```

### Thanks

Thanks to @alloy for pointing out the inherent code security and 
interoperability problems with Vapor.js; and suggesting to
leverage the semicolon solution to address the underlying issues.


### License

(c) Copyright 2012 Thomas Fuchs

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

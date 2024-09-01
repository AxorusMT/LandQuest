# ch


- Church numerals are the most common way of storing natural numbers (i.e. positive integers greater than 0) 
- They are represented by the number of times some function, e.g. $f$ is applied to some variable, e.g. $x$.
- For example, if $f$ is applied to $x$ once:  $f(x)$, then that would represent 1.
	- 2 would be $f(f x)$
	- 3 would be $f(f(f\,x)$ etc...
	- 0 would be no applications, so just $x$.
- Using the lambda calculus, church numerals would be written as follows:
$$
\displaylines{
	0 = \lambda{fx}.x \\
	1 = \lambda{fx}.f\,x \\
	2 = \lambda{fx}.f(f\,x) \\
	3 = \lambda{fx}.f(f(f\,x)) \\
	\vdots \\
	n = \lambda{fx}.f^{\circ n}\,x
}
$$
## Mathematical Operations

### Successor
- The successor function, $succ$, can be thought of as "adds one", as for any natural number $n$, it produces $n+1$. 
- Example use of the $succ$ function, with a full reduction to the $\beta$-normal form.
$$
\displaylines{
	succ\;2 \\
	(\lambda{nfx}.f(nfx))\;2 \\
	(\lambda{nfx}.f(nfx))\;(\lambda{fx}.f(f\,x)) \\
	(\lambda{nfx}.f(nfx)) \qquad [n=(\lambda{fx}.f(f\,x))] \\
	(\lambda{fx}.f(\lambda{fx}.f(f\,x))fx))	\\
	(\lambda{fx}.f(f(f\,x)))) = 3 \\
	\boxed{\therefore succ\;2 =_{\beta} 3} 
}
$$
### Addition
- The addition function adds two natural numbers, $n$ and $m$, and then reduces to $n + m$.
- This is done using the $plus$ function, which is defined as:
$$
plus = \lambda{nmfx}.nf(m\,f\,x) = \lambda{nm}.n\,succ\,m
$$
- Notice how we use the $succ$ function from before, so $n + m$ is simply the application of $succ$ to $m$ $n$ times.
- Here is an example use of the $plus$ function.
$$
\displaylines{
	plus\;1\;1 \\
	\lambda{nmfx}.nf(m\,f\,x) \, 1 \, 1\\
	\lambda{nmfx}.nf(m\,f\,x) \qquad [n = (\lambda{fx}.f(x), \, m = (\lambda{fx}.f(x)] \\
	(\lambda{fx}.(\lambda{fx}.f(x) \, f( (\lambda{fx}.f(x))\,f\,x))  \qquad [f = f, x = x]  \\
	(\lambda{fx}.(\lambda{fx}.f(x) \, f(f(x))  \qquad [f = f(f(x))] \\
	(\lambda{fx}.(\lambda{x}.f(f(x))\,x)) \qquad [x = x] \\
	\lambda{fx}.f(f(x)) = 2 \\
	\boxed{\therefore plus\;1 \;1 =_{\beta} 2} 
	
	% TODO(mwini): Finish this shit later, even this is hurting my head LOL!
}
$$
- This also means that $succ\; 2 =_{\beta} plus\;2\;2$ 


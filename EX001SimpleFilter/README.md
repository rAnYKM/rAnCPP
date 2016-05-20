# Simple Filter

## Input:

### origin char* original string
### sensitive char* sensitive string that needs to be striped
### nonsense char* chacters with no meanings that can be ignored

## Output:

### the string without sensitive or nonsense information

## Examples:

	Ca<ts l>ike e<a>ting s<>e>lfish o>n th<e s>>h<<elf.
	Sensitive: sel Nonsense: <>
	Output: Cats like eating fish on the shelf.

## Attention:
1. To avoid the disambiguation, the sensitive string will not include nonsense characters.
2. Please consider the recursive situation. (e.g. sselelf -> self -> f)
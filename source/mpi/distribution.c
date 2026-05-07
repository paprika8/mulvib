#include <stdlib.h>
#include <stdio.h>

#define ll long long

void getreaddr_(int *irank, int *n, ll *limQN, ll *lenLim, ll* readdr, ll* NMatx, ll *q_offset, ll *block_size, ll *conf_start, ll *conf_end)
{
	ll i;
	int limit_block = 1;

	limit_block = *NMatx / *n;
	i = limit_block * *irank;

	if (*irank < *NMatx % *n)
		i += *irank;
	else
		i += *NMatx % *n;

	if (*NMatx % *n > *irank)
		limit_block++;

	ll offset = i;
	*q_offset = offset + 1; //to fortran index
	*block_size = limit_block;

	int limit = 1;
	for (i = 0; i < *lenLim; i++)
		limit *= limQN[i];
	i = 0;
	offset ++; //to fortran index
	for(; i < limit; ++i)
		if(readdr[i] == offset) {*conf_start = i + 1; break;}
	offset += limit_block - 1;
	for(; i < limit; ++i)
		if(readdr[i] == offset) {*conf_end = i + 1; break;}
	return;
}

#include <stdlib.h>
#include <stdio.h>

#define ll long long

void nstDo(ll *Ic, ll NDo, ll *NMax)
{
	ll n = 0;
d10:
	Ic[n] = Ic[n] + 1;
	if (Ic[n] <= NMax[n])
		return;
	else
	{
		Ic[n] = 1;
		n = n + 1;
		if (n <= NDo)
			goto d10;
	}
}

void MCoCal(ll num, ll *Ic, ll NDo, ll *NMax)
{
	ll out = num - 1;
	ll i = 0;
	for (; i < NDo; ++i)
	{
		Ic[i] = (out % NMax[i]) + 1;
		out = out / NMax[i];
		if (out == 0)
		{
			++i;
			break;
		}
	}
	for (; i < NDo; ++i)
		Ic[i] = 1;
}

void getreaddr_(ll *irank, ll *limQN, ll *Indxx, ll *len, ll *n, ll *q_offset, ll *block_size)
{
	ll i;
	ll *ic = malloc(sizeof(ll) * *len);
	int limit_block = 1;
	int limit = 1;
	for (i = 0; i < *len; i++)
	{
		ic[i] = 1;
		limit *= limQN[i];
	}

	char *buf = malloc(limit);
	for (i = 0; i < limit; i++)
		buf[i] = 0;

	limit_block = limit / *n;
	i = limit_block * *irank;

	if (*irank < limit % *n)
		i += *irank;
	else
		i += limit % *n;

	if (limit % *n > *irank)
		limit_block++;

	ll offset = i;
	*q_offset = offset + 1;
	*block_size = limit_block;
	return;

	/*ll j;
	MCoCal(i + 1, ic, *len, limQN);
	for (i = 0; i < limit_block; i++)
	{
		for (int k = 0; k < *len; ++k)
		{
			if (ic[k] > 1)
			{
				j = i - Indxx[k] + offset;
				buf[j] = 1;
			}
			if (ic[k] < limQN[k])
			{
				j = i + Indxx[k] + offset;
				buf[j] = 1;
			}
		}
		buf[i + offset] = 1;
		nstDo(ic, *len, limQN);
	}

	ll res = buf[0];
	ll n_offset = buf[0];
	for (i = 1; i < limit; i++)
	{
		res += buf[i];
		if (buf[i] && (i < 1 || !buf[i - 1]))
		{
			n_offset++;
		}
	}

	ll *offset_p = malloc(n_offset * sizeof(ll) * 2 + sizeof(ll) * 2);
	ll it = 0;
	for (i = 0; i < limit; i++)
	{
		if (buf[i] && (i < 1 || !buf[i - 1]))
			offset_p[it * 2] = i;
		if (buf[i] && (i + 1 >= limit || !buf[i + 1]))
		{
			if (it)
				offset_p[it * 2 + 1] = i - offset_p[it * 2] + 1 + offset_p[(it - 1) * 2 + 1];
			else
				offset_p[it * 2 + 1] = 0;
			it++;
			offset_p[it * 2] = i + 1;
			offset_p[it * 2 + 1] =  -1;
		}
	}

	printf("Block %lld res = %lld \\ %lld\n percent = %lf\n", *irank, res, limit, ((double)res) / limit);
	printf("offset %lld\n", n_offset);
	free(ic);
	free(buf);
	for(int i = 0; i < n_offset; ++i)
		printf("%lld > readdr=%lld\n", offset_p[i * 2], offset_p[i * 2 + 1]);
	free(offset_p); //TODO реадресация, удалить или внедрить
*/

}
// b distribution.c:70

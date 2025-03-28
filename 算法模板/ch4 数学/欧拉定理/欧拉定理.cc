/*
若a与n互质，则a^phi(n) === 1 (mod n)
证明：设k = phi(n)
1 ~ n中与n互质的数为：a1 a2 a3 ... ak

则 a*a1 a*a2 a*a3 ... a*ak 均mod n后也都与n互质
下证明a*ai(mod n) 与 a*aj (mod n) 不相等：
反证法：若a * ai === a * aj (mod n)因为a与n互质 所以
ai === aj (mod n) 但是已知ai 与 aj 不相等 矛盾
所以a*ai != a*aj (mod n)

所以：a*a1(mod n) a*a2(mod n) ... a*ak(mod n) 也是1~n内与n互质的所有数

则：a*a1 * a*a2 * a*a3 *...* a*ak === a1*a2*a3*...*ak (mod n)
a^k * a1*a2*a3*...*ak === a1*a2*a3*...*ak (mod n)
a1*a2*a3*...ak 与 n 互质
则：a^k === 1 (mod n)
*/

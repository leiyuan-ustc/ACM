//顺时针排序

struct Point
{
	int x, y;
	int num;
	Point(int x = 0, int y = 0): x(x), y(y) {}
} a[50100];
typedef Point Vector;
Vector operator - (Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
int Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}
int Length(Vector A)
{
	return (A.x * A.x + A.y * A.y);
}
int n;
int cmp(const Point A, const Point B)
{
	Vector P1 = A - a[1], P2 = B - a[1];
	int tmp = Cross(P1, P2);
	return ((tmp < 0) || (tmp == 0 && Length(P1) < Length(P2)));
}
int main()
{
	//一共n个点
	int tmp = 1;
	for (int i = 2; i <= n; i++)
	{
		if ((a[i].y < a[tmp].y) || (a[i].y == a[tmp].y && a[i].x < a[tmp].x)) tmp = i;
	}
	swap(a[1], a[tmp]); //寻找左下角的点作为基准
	sort(a + 2, a + n + 1, cmp);
	Vector q[50100];
	int head = 1;
	q[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		while (head > 1 && Cross(q[head] - q[head - 1], a[i] - q[head]) >= 0)	//不包括共线的点
			head--;
		head++;
		q[head] = a[i];
	}
	q[0] = q[head];
	q[head + 1] = q[1];

	//将凸包上的点存在q中

}
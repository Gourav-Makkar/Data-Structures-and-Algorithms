class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
         int area1 = (C-A)*(D-B), area2 = (G-E)*(H-F);
         int coverX = C < E ? 0 : C < G ? A < E ? C-E : C-A : A > G ? 0 : A < E ? G-E : G-A;
         int coverY = D < F ? 0 : D < H ? B < F ? D-F : D-B : B > H ? 0 : B < F ? H-F : H-B;
         return area1 + area2 - coverX * coverY;
    }
};
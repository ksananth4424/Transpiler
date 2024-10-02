#include<bits/stdc++.h>

float total_area(std::deque<float> h, std::deque<float> b) {
float sum = 0;
for(int i = 0;i < h.size() and i < b.size();) {
sum = sum + h[i] * b[i];
i = i + 1;
if (!(i < h.size() and i < b.size())) {
{
return;
}
}
}
}

int main() {
std::deque<float> h, b;
h.push_back(0.5);
b.push_back(3);
h.push_back(1.5);
b.push_back(2);
h.push_back(2.5);
b.push_back(1);
float x;
x[0] = h.front();
h.pop_front();
std::cout << total_area(h, b) << '\n';
}
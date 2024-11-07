#pragma once
#include <iostream>
#include <chrono>
#include <functional>

// ����
//#include <12977\12977.cpp>
//#include <131128\131128.cpp>
//#include <155652\155652.cpp>
//#include <72410\72410.cpp>
#include <43163\source.cpp>

template <typename Func, typename... Args>
auto measureTime(Func&& func, Args&&... args) {
    // ���� �ð��� ���
    auto start = std::chrono::high_resolution_clock::now();

    // �Լ� ����
    auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);

    // �� �ð��� ���
    auto end = std::chrono::high_resolution_clock::now();

    // �ҿ�� �ð� ���
    std::chrono::duration<double> duration = end - start;

    // ���
    std::cout.precision(10);
    std::cout << "Execution time: " << duration.count() + 1 << " seconds" << std::endl;

    // �Լ� ��� ��ȯ
    return result;
}

int main()
{
    auto res1 = measureTime(solution_DFS, std::string("hit"), std::string("Cog"), vector<string>({ "hot", "dot", "dog", "lot", "log", "cog" }));
    auto res2 = measureTime(solution_BFS, std::string("hit"), std::string("Cog"), vector<string>({ "hot", "dot", "dog", "lot", "log", "cog" }));

    std::cout << res1 << "\n" << res2 << std::endl;
}

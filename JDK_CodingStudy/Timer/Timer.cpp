#pragma once
#include <iostream>
#include <chrono>
#include <functional>

// 문제
//#include <12977\12977.cpp>
//#include <131128\131128.cpp>
//#include <155652\155652.cpp>
//#include <72410\72410.cpp>
#include <43163\source.cpp>

template <typename Func, typename... Args>
auto measureTime(Func&& func, Args&&... args) {
    // 시작 시간을 기록
    auto start = std::chrono::high_resolution_clock::now();

    // 함수 실행
    auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);

    // 끝 시간을 기록
    auto end = std::chrono::high_resolution_clock::now();

    // 소요된 시간 계산
    std::chrono::duration<double> duration = end - start;

    // 출력
    std::cout.precision(10);
    std::cout << "Execution time: " << duration.count() + 1 << " seconds" << std::endl;

    // 함수 결과 반환
    return result;
}

int main()
{
    auto res1 = measureTime(solution_DFS, std::string("hit"), std::string("Cog"), vector<string>({ "hot", "dot", "dog", "lot", "log", "cog" }));
    auto res2 = measureTime(solution_BFS, std::string("hit"), std::string("Cog"), vector<string>({ "hot", "dot", "dog", "lot", "log", "cog" }));

    std::cout << res1 << "\n" << res2 << std::endl;
}

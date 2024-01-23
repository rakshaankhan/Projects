#include <iostream>
#include <vector>

class Term {
public:
    double gpa;
    int credits;

    Term(double gpa, int credits) : gpa(gpa), credits(credits) {}
};

double calculateCumulativeGPA(const std::vector<Term>& terms) {
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (const auto& term : terms) {
        totalGradePoints += term.gpa * term.credits;
        totalCredits += term.credits;
    }

    return totalCredits == 0 ? 0 : totalGradePoints / totalCredits;
}

int main() {
    std::vector<Term> terms;
    int numTerms;
    std::cout << "Enter the number of Semesters: ";
    std::cin >> numTerms;

    for (int i = 0; i < numTerms; ++i) {
        double gpa;
        int credits;
        std::cout << "Enter GPA for Semester " << (i + 1) << ": ";
        std::cin >> gpa;
        std::cout << "Enter total credits for Semester " << (i + 1) << ": ";
        std::cin >> credits;
        terms.emplace_back(gpa, credits);
    }

    double cumulativeGPA = calculateCumulativeGPA(terms);
    std::cout << "Your cumulative GPA is: " << cumulativeGPA << std::endl;

    return 0;
}

#pragma once
#pragma once

namespace UniversityRecords {

    using namespace System;

    public ref class Enrollment {
    public:
        String^ enrollmentID;
        String^ studentID;
        String^ courseID;
        String^ semester;
        String^ grade;

        Enrollment(String^ enrollmentID, String^ studentID, String^ courseID, String^ semester, String^ grade) {
            this->enrollmentID = enrollmentID;
            this->studentID = studentID;
            this->courseID = courseID;
            this->semester = semester;
            this->grade = grade;
        }
    };
}

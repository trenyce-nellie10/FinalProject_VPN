#pragma once
#pragma once

namespace UniversityRecords {

    using namespace System;

    public ref class Course {
    public:
        String^ courseID;
        String^ courseName;
        int credits;

        Course(String^ courseID, String^ courseName, int credits) {
            this->courseID = courseID;
            this->courseName = courseName;
            this->credits = credits;
        }
    };
}

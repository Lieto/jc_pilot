//
// Created by kuoppves on 21.8.2016.
//

#ifndef JC_PILOT_DETECTEDPERSON_H
#define JC_PILOT_DETECTEDPERSON_H

#include <iostream>
#include <ctime>
#include <opencv2/opencv.hpp>
#include "MovingAvgVal.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"

class DetectedPerson {

    MovingAvgVal age;
    MovingAvgVal gender;
    int detectionCount;
    bool detected = false;
    int detectionFrameNo = -1;
    int lastObservedFrame = -1;
    time_t firstObservedTimestamp;
    time_t lastObserved;

    bool sent = false;
    cv::Point gaze;
    int crowdSightID;
    int attentionSpan = 0;

private:

    int personId;

public:

    static int idCounter;

    time_t getLastObserved() const {
        return lastObserved;
    }

    void setLastObserved(time_t lObserved) {
        lastObserved = lObserved;
    }

    int getPersonId() const {
        return personId;
    }

    void setPersonId() {
        personId = idCounter++;

    }

    int getCrowdSightID() const {
        return crowdSightID;
    }

    void setCrowdSightID(int id) {
        crowdSightID = id;
    }

    float getGender() {
        gender.calcValue();
        return gender.getValue();
    }

    std::string getGenderString() {
        gender.calcValue();
        return ((gender.getValue()) < 0 ? "mies":"nainen");
    }

    float getAge() {
        age.calcValue();
        return age.getValue();
    }

    void addAge(int a) {
        age.addValue(a);
    }

    void addGender(float g) {
        gender.addValue(g);
    }

    void incrementDetectionCount() {
        detectionCount++;
    }

    int getDetectionCount() const {
        return detectionCount;
    }

    void setDetectionCount(int dCount) {
        detectionCount = dCount;
    }

    bool getDetected() const {
        return detected;
    }

    void setDetected(bool d) {
        detected = d;
    }

    time_t getFirstObservedTimeStamp() const {
        return firstObservedTimestamp;
    }

    void setFirstObservedTimestamp(time_t dTimestamp) {
        firstObservedTimestamp = dTimestamp;
    }

    bool isSent() const {
        return sent;
    }

    void setSent(bool s) {
        sent = s;
    }

    const cv::Point &getGaze() const {
        return gaze;
    }

    void setGaze(const cv::Point &g) {
        gaze = g;
    }

    int getDetectionFrameNo() const {
        return detectionFrameNo;
    }

    void setDetectionFrameNo(int dFrameNo) {
        detectionFrameNo = dFrameNo;
    }

    int getAttentionSpan() const {
        return attentionSpan;
    }

    void setAttentionSpan(int aSpan) {
        attentionSpan = aSpan;
    }

    void setLastObservedFrame(int i) {
        lastObservedFrame = i;
    }

    int getLastObservedFrame() const {
        return lastObservedFrame;
    }

    std::string asJSON(int frameID, int unitID);


};


#endif //JC_PILOT_DETECTEDPERSON_H

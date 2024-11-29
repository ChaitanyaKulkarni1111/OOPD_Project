#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

class AccessPoint {
private:
    int id;
    int bandwidthMHz; // Channel bandwidth in MHz
    double utilization;        // Channel utilization (0.0 to 1.0)
public:
    AccessPoint(int id, int bandwidth);
    int getBandwidth() const;
    void updateUtilization(double usage);
    double getUtilization() const;
};

#endif // ACCESSPOINT_H

#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
class ParkingCalculator
{
public:
    ParkingCalculator(int _DefaultTime, int _DefaultRate, int _UnitTime, int _UnitRate)
        : DefaultTime(_DefaultTime), DefaultCharge(_DefaultRate), UnitTime(_UnitTime), UnitCharge(_UnitRate)
    {
    }

private:
    struct TimeInfo
    {
        int TimeToIn= 0; // ���� �ð�
        int AccumulatedTime = 0; // ���� ���� �ð�
    };

    map<int, TimeInfo> AccessRecord;
    vector<int> ChargeRecord;

    int DefaultTime; // �⺻ �ð�
    int DefaultCharge; // �⺻ ���
    int UnitTime; // ���� �ð�
    int UnitCharge; // ���� �ð�

public:
    void RecordProcessing(int _Minute, int _VehicleNum, const string& _Process)
    {
        if (_Process == "IN")
        {
            CheckIn(_VehicleNum, _Minute);
        }
        else if (_Process == "OUT")
        {
            CheckOut(_VehicleNum, _Minute);
        }
    }

    void CheckIn(int _VehicleNum, int _Minute)
    {
        AccessRecord[_VehicleNum].TimeToIn = _Minute;
    }

    void CheckOut(int _VehicleNum, int _Minute)
    {
        int ParkingTime = _Minute - AccessRecord[_VehicleNum].TimeToIn; // ������ �ð� ���
        AccessRecord[_VehicleNum].AccumulatedTime += ParkingTime; // ���� �ð� ����
        AccessRecord[_VehicleNum].TimeToIn = -1; // ���� �ð��� -1�̸� CheckOut�� ������ ����
    }

    void ChargeSettlement()
    {
        CheckOutRemainingVehicles(); // ���� ���� CheckOut ��Ű��
        for (const pair<int, TimeInfo>& Record : AccessRecord)
        {
            CalculationOfCharge(Record.second.AccumulatedTime); // ��� ����
        }
    }

    const vector<int>& GetChargeRecord()
    {
        return ChargeRecord;
    }

private:
    void CheckOutRemainingVehicles()
    {
        for (const pair<int, TimeInfo>& Record : AccessRecord)
        {
            if (Record.second.TimeToIn != -1) // CheckOut�� �ȵ� ���� ����
            {
                CheckOut(Record.first, 1439); // 23:59 CheckOut���� �ð� ����
            }
        }
    }

    void CalculationOfCharge(int _ParkingTime)
    {
        int Charge = DefaultCharge; // �⺻ ���
        if (DefaultTime < _ParkingTime)
        {
            int OverTime = ceil(float(_ParkingTime - DefaultTime) / UnitTime); // �߰� �ð�
            Charge += OverTime * UnitCharge; // �߰� ��� ���
        }

        ChargeRecord.push_back(Charge);
        return;
    }
};

vector<int> solution(vector<int> fees, vector<string> records) 
{
    ParkingCalculator PC(fees[0], fees[1], fees[2], fees[3]);

    // Record ó��
    for (const string& Record : records)
    {
        stringstream ss(Record);
        string Time, Process;
        int VehicleNum;

        ss >> Time >> VehicleNum >> Process;

        int Hour = stoi(Time.substr(0, 2));
        int Minute = stoi(Time.substr(3, 2));
        Minute += Hour * 60;
        
        PC.RecordProcessing(Minute, VehicleNum, Process);
    }

    PC.ChargeSettlement(); // ���� ��� ����
    return PC.GetChargeRecord();
}

int main()
{
    solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
}
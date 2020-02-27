#include "query.h"
#include "responses.h"

class BusManager {
public:
  void AddBus(const string& bus, const StopList& stops);

  BusesForStopResponse GetBusesForStop(const string& stop) const;

  StopsForBusResponse GetStopsForBus(const string& bus) const;

  AllBusesResponse GetAllBuses() const;
private:
  map<string, StopList> buses;
  map<string, StopList> busStops;
};    

#include "Snowflake.h"
#include "getTime.h"

Snowflake::Snowflake(void)
{
	this->epoch = 0;
	this->time = 0;
	this->machine = 0;
	this->sequence = 0;
}

Snowflake::~Snowflake(void)
{
}

void Snowflake::setEpoch(uint64_t epoch)
{
	this->epoch = epoch;
}

void Snowflake::setMachine(int machine)
{
	this->machine = machine;
}

int64_t Snowflake::generate()
{
	int64_t value = 0;
	uint64_t time = getTime() - this->epoch;

	//�ð� 41bit
	value |= time << 22;

	//�ӽ� 10bit
	value |= this->machine & 0x3FF << 12;

	//�ð��� ���ϸ� ������ �ʱ�ȭ
	if(time!=this->time) {
		this->time = time;
		this->sequence = 0;
	}

	//������ 12bit
	value |= this->sequence++ & 0xFFF;

	return value;
}

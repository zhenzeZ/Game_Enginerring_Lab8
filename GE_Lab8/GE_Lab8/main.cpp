#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <sstream>

#include "Player.h"

using namespace std;

int m_max = 20;

atomic_int m_currentTicket = 0;
atomic_int m_nextTicket = 0;

mutex m_mutex;

Player m_player;

void physic1() {
	int end = false;
	int i = m_max;

	while (!end) {
		while (m_max > 0) {

			int ticketNumber = m_nextTicket++;

			//waitint for ticket
			while (m_currentTicket != ticketNumber)
			{
				continue;
			}

			this_thread::sleep_for(chrono::seconds(0)); // waiting

			m_mutex.lock();
			m_player.position.x += rand() % 5;
			m_player.position.y += rand() % 5;
			std::cout << "physic1: ticket: " << ticketNumber << ", position = (" << m_player.position.x << " , " << m_player.position.y << " )" << std::endl;
			m_mutex.unlock();

			m_currentTicket++;
			m_max--;
			//i--;
		}

		end = true;
	}
}

void physic2() {
	int end = false;
	int i = m_max;

	while (!end) {
		while (m_max > 0) {

			int ticketNumber = m_nextTicket++;

			//waitint for ticket
			while (m_currentTicket != ticketNumber)
			{
				continue;
			}

			this_thread::sleep_for(chrono::seconds(0)); // waiting

			m_mutex.lock();
			m_player.position.x -= rand() % 5;
			m_player.position.y -= rand() % 5;
			std::cout << "physic2: ticket: " << ticketNumber << ", position = (" << m_player.position.x << " , " << m_player.position.y << " )" << std::endl;
			m_mutex.unlock();

			m_currentTicket++;
			m_max--;
		}

		end = true;
	}
}

void input() {
	int end = false;
	int i = m_max;

	while (!end) {
		while (m_max > 0) {

			int ticketNumber = m_nextTicket++;

			//waitint for ticket
			while (m_currentTicket != ticketNumber)
			{
				continue;
			}

			this_thread::sleep_for(chrono::seconds(0)); // waiting

			m_mutex.lock();
			m_player.position.x = rand() % 5;
			m_player.position.y = rand() % 5;
			std::cout << "input: ticket: " << ticketNumber << ", position = (" << m_player.position.x << " , " << m_player.position.y << " )" << std::endl;
			m_mutex.unlock();

			m_currentTicket++;
			m_max--;
		}

		end = true;
	}
}

void render() {
	int end = false;
	int i = m_max;

	while (!end) {
		while (m_max > 0) {

			int ticketNumber = m_nextTicket++;

			//waitint for ticket
			while (m_currentTicket != ticketNumber)
			{
				continue;
			}

			this_thread::sleep_for(chrono::seconds(0)); // waiting

			m_mutex.lock();
			//m_player.position.x = rand() % 5;
			//m_player.position.y = rand() % 5;
			std::cout << "render: ticket: " << ticketNumber << ", position = (" << m_player.position.x << " , " << m_player.position.y << " )" << std::endl;
			m_mutex.unlock();

			m_currentTicket++;
			m_max--;
		}

		end = true;
	}
}

int main()
{
	srand(time(NULL));

	thread m_physic1 = thread(physic1);
	thread m_physic2 = thread(physic2);
	thread m_input = thread(input);  
	thread m_render = thread(render);

	m_physic1.join();
	m_physic2.join();
	m_input.join();
	m_render.join();


	return 0;
}
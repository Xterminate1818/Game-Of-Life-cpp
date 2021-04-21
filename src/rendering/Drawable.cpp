#include "Drawable.h"

Uint32 Drawable::WHITE = -1;
Uint32 Drawable::BLACK = 0;

bool Drawable::Compare::operator() (const Drawable* a, const Drawable* b) {
	return a->layer > b->layer;
}

void Drawable::add(Drawable* d) {
	m_render_queue.push(d);
}

void Drawable::drawScreen() {
	while (!m_render_queue.empty()) {
		Drawable* temp = m_render_queue.top();
		m_render_queue.pop();
		if (temp) {
			temp->draw();
		}
		else {
			std::cout << "Warning: nullpointer in draw queue" << std::endl;
		}
	}
}

std::priority_queue<Drawable*, std::vector<Drawable*>, Drawable::Compare> Drawable::m_render_queue;
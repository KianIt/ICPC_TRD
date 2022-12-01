template <typename T>
struct line { // expressed as two vectors
    vec<T> start, dir;
    line() { }
    line(vec<T> a, vec<T> b) : start(a), dir(b - a) { }
    
    vec<ld> intersect(line l) {
        ld t = ld((l.start - start) ^ l.dir) / (dir ^ l.dir);
        // For segment-segment intersection this should be in range [0, 1]
        vec<ld> res(start.x, start.y);
        vec<ld> dirld(dir.x, dir.y);
        return res + dirld * t;
    }
};

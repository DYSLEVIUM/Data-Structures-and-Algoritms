func stringHash(s string, k int) string {
    n := len(s)
    substr := uint16(n / k)

    hash_fn := func (sum *uint16) rune {
        return rune(*sum % 26);
    }

    var wg sync.WaitGroup
    var sm sync.Map

    wg.Add(int(substr))
    for i := uint16(0); i < substr; i++ {
        go func(){
            defer wg.Done()

            sum := uint16(0)
            for _, ch := range s[i * uint16(k) : (i + 1) * uint16(k)] {
                sum += uint16(ch) - 'a'
            }
            curr := string(hash_fn(&sum) + 'a')
            sm.Store(i, curr)
        }()
    }
    wg.Wait()

    var hashBuffer bytes.Buffer
    for i := uint16(0); i < substr; i++ {
        val, _ := sm.Load(i)
        hashBuffer.WriteString(val.(string))
    }

    return hashBuffer.String()
}
